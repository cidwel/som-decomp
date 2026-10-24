.setcpu "65816"
.segment "CODE"
.org $28EB
map_control_0f28eb:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
