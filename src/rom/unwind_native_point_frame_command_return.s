; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-producer.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A699
unwind_native_point_frame_command_return:
    ply
    sec
    rts
