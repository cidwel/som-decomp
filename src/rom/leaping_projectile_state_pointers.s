; Numeric projectile state/direction metadata; see docs/graphics.md.
.setcpu "65816"
initialize_leaping_projectile_animation_and_motion_callback = $7464
update_leaping_projectile_direction_velocity_and_collision = $7480
finish_leaping_projectile_when_animation_word_is_zero = $74EE
.segment "CODE"
.org $745E
leaping_projectile_state_pointers:
    .word initialize_leaping_projectile_animation_and_motion_callback, update_leaping_projectile_direction_velocity_and_collision, finish_leaping_projectile_when_animation_word_is_zero
