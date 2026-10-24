; Named event bytecode operands; no dialogue payload.
.macro event_actor_animation actor_selector, animation
    .byte $31, actor_selector, animation
.endmacro

.macro event_actor_animation_loop actor_selector, animation
    .byte $34, actor_selector, animation
.endmacro

.macro event_actor_effect effect_selector
    .byte $2E, effect_selector
.endmacro

.macro event_actor_effect_0e 
    .byte $0E
.endmacro

.macro event_actor_effect_0f 
    .byte $0F
.endmacro

.macro event_actor_walk actor_selector, direction, frames
    .byte $32, actor_selector, (direction << 6) | frames
.endmacro

.macro event_audio_request command_id, request_id, parameter2, parameter3
    .byte $40, command_id, request_id, parameter2, parameter3
.endmacro

.macro event_call target_event
    .byte $20 | (target_event >> 8), target_event & $FF
.endmacro

.macro event_change_map transition_index
    .byte $18 | (transition_index >> 8), transition_index & $FF
.endmacro

.macro event_clone_actor actor_selector
    .byte $2B, actor_selector
.endmacro

.macro event_decrement_flag flag_index
    .byte $2A, flag_index
.endmacro

.macro event_delete_actor actor_selector
    .byte $2C, actor_selector
.endmacro

.macro event_end 
    .byte $00
.endmacro

.macro event_freeze 
    .byte $06
.endmacro

.macro event_gather 
    .byte $03
.endmacro

.macro event_hero_command command_selector
    .byte $1E, command_selector
.endmacro

.macro event_increment_flag flag_index
    .byte $29, flag_index
.endmacro

.macro event_jump target_event
    .byte $10 | (target_event >> 8), target_event & $FF
.endmacro

.macro event_native_command_35 
    .byte $35
.endmacro

.macro event_noop 
    .byte $01
.endmacro

.macro event_object_command_36 command_word
    .byte $36
    .word command_word
.endmacro

.macro event_object_command_37 command_word
    .byte $37
    .word command_word
.endmacro

.macro event_party_command command_selector
    .byte $1F, command_selector
.endmacro

.macro event_redraw_pieces 
    .byte $0A
.endmacro

.macro event_refresh_objects 
    .byte $09
.endmacro

.macro event_restore_hero hero_selector_and_flags
    .byte $2F, hero_selector_and_flags
.endmacro

.macro event_return 
    .byte $02
.endmacro

.macro event_screen screen_operation
    .byte $2D, screen_operation
.endmacro

.macro event_screen_word screen_operation, screen_parameter
    .byte $2D, screen_operation
    .word screen_parameter
.endmacro

.macro event_set_actor_field actor_selector, field_offset, value
    .byte $39, actor_selector, field_offset, value
.endmacro

.macro event_set_flag flag_index, value
    .byte $30, flag_index, value
.endmacro

.macro event_test_actor actor_selector
    .byte $38, actor_selector
.endmacro

.macro event_test_actor_field predicate_selector, actor_selector, field_offset, operand
    .byte $48 | predicate_selector, actor_selector, field_offset, operand
.endmacro

.macro event_test_flag_range flag_index, minimum, maximum
    .byte $42, flag_index, (minimum << 4) | maximum
.endmacro

.macro event_toggle_visibility_04 
    .byte $04
.endmacro

.macro event_toggle_visibility_05 
    .byte $05
.endmacro

.macro event_unfreeze 
    .byte $07
.endmacro

.macro event_wait ticks
    .byte $28, ticks
.endmacro

.macro event_wait_idle 
    .byte $08
.endmacro

.macro event_warp destination_index
    .byte $1C, destination_index
.endmacro

.macro event_world_transition destination_and_flags
    .byte $1D, destination_and_flags
.endmacro
