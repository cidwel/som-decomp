; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-enemy-group-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_animation_and_resume_native_frame_stream = $F4CB

.segment "CODE"
.org $FD1F
tail_dispatch_ordinary_enemy_animation_step:
    jmp advance_actor_animation_and_resume_native_frame_stream
