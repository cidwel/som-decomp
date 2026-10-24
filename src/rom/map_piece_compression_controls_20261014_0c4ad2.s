.setcpu "65816"
.segment "CODE"
.org $4AD2
map_control_0c4ad2:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
