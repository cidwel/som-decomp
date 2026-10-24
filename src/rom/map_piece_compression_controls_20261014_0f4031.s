.setcpu "65816"
.segment "CODE"
.org $4031
map_control_0f4031:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
