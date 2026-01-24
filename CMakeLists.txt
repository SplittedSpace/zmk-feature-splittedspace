target_sources(app PRIVATE src/behaviors/behavior_indicators.c)

if (CONFIG_ZMK_BEHAVIOR_INDICATORS)
  target_sources(app PRIVATE src/events/indicators_changed.c)
  target_sources(app PRIVATE src/behaviors/behavior_indicators.c)
endif()

target_sources_ifdef(CONFIG_ZMK_LED_WIDGETS app PRIVATE src/led_widgets.c)
