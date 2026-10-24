.setcpu "65816"
.segment "CODE"
.org $9872
map_control_0d9872:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
