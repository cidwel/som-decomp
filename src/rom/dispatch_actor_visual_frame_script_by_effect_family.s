; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

advance_and_finish_native_motion_effect_frame_script = $81AF
advance_and_finish_native_ordinary_cast_frame_script = $8245
advance_native_cell_cast_frame_script_and_homing_cell = $824E

.segment "CODE"
.org $818F
dispatch_actor_visual_frame_script_by_effect_family:
    sep #$20
    stz a:$E00C,X
    .a8
    and #$E0
    .a8
    cmp #$80
    bne dispatch_actor_visual_frame_script_by_effect_family_c1819e
    jsr advance_and_finish_native_ordinary_cast_frame_script
    rtl
dispatch_actor_visual_frame_script_by_effect_family_c1819e:
    .a8
    cmp #$E0
    bne dispatch_actor_visual_frame_script_by_effect_family_c181a6
    jsr advance_native_cell_cast_frame_script_and_homing_cell
    rtl
dispatch_actor_visual_frame_script_by_effect_family_c181a6:
    .a8
    cmp #$C0
    bne dispatch_actor_visual_frame_script_by_effect_family_c181ae
    jsr advance_and_finish_native_motion_effect_frame_script
    rtl
dispatch_actor_visual_frame_script_by_effect_family_c181ae:
    rtl
