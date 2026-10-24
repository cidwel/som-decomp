.setcpu "65816"
.segment "CODE"
.org $29DA
map_control_0f29da:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
