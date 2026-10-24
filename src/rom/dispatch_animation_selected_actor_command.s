; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

boss_external_actor_command_if_selected = $3963

.segment "CODE"
.org $1A1E
dispatch_animation_selected_actor_command:
    lda [$76],Y
    iny
    iny
    phy
    jsr boss_external_actor_command_if_selected
    ply
    ldx $87
    rts
