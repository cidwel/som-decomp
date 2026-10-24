.setcpu "65816"
.segment "CODE"
.org $3DDC
map_control_0f3ddc:
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
