#include "color.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

rgba_color rgba_color_new(float r, float g, float b, float a) {
  __debug__("Creating color from: %f %f %f %f\n", r, g, b, a);
  rgba_color color = {
    .r = r,
    .g = g,
    .b = b,
    .a = a,
  };

  return color;
}

rgba_color hsl_to_rgb(float h, float s, float l) {
    float c = (1 - fabsf(2 * l - 1)) * s;
    float x = c * (1 - fabsf(fmodf(h * 6, 2) - 1));
    float m = l - c/2;
    
    float r = 0, g = 0, b = 0;
    if(h < 1.0/6.0)      { r = c; g = x; b = 0; }
    else if(h < 2.0/6.0) { r = x; g = c; b = 0; }
    else if(h < 3.0/6.0) { r = 0; g = c; b = x; }
    else if(h < 4.0/6.0) { r = 0; g = x; b = c; }
    else if(h < 5.0/6.0) { r = x; g = 0; b = c; }
    else                 { r = c; g = 0; b = x; }
    
    return rgba_color_new(r + m, g + m, b + m, 1.0);
}

rgba_color get_rainbow_color(float position, float time) {
    // Schnellere Farbrotation und weichere Übergänge
    float hue = fmodf(position * 0.3 + time * 0.4, 1.0);
    return hsl_to_rgb(hue, 1.0, 0.5);
}

rgba_color rgba_color_string(char *const src) {
  __debug__("Creating color from string: %s\n", src);
  // Implementation note:
  //
  // Due to the way that the parsing is done, it automatically takes care of
  // the edge case of a negative value.

  rgba_color color;

  float *ptrs[4] = {
    &color.r,
    &color.g,
    &color.b,
    &color.a,
  };

  char *token;
  for (int i = 0; i < 4; i++) {
    // The compiler will (probably) optimize away this logic.
    if (i == 0) {
      token = strtok(src, COLOR_SEPARATOR);
    } else {
      token = strtok(NULL, COLOR_SEPARATOR);
    }

    if (token == NULL) {
      return rgba_color_new(0, 0, 0, -1.0);
    }

    float f = atof(token);
    // Clamp to 1.0 max.
    if (f > 1.0) {
      f = 1.0;
    }

    __debug__("Got color component: %f\n", f);
    *ptrs[i] = f;
  }

  return color;
}
