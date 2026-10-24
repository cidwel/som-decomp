; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4F7D
publish_native54_projectile_depth_and_dispatch_phase:
    lda a:$0032,X
    sta a:$0022,X
    lda a:$0094,X
    asl
    tax
    jmp ($4F8B,X)
