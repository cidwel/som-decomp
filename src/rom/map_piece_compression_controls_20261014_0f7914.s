.setcpu "65816"
.segment "CODE"
.org $7914
map_control_0f7914:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
