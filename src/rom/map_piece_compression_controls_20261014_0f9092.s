.setcpu "65816"
.segment "CODE"
.org $9092
map_control_0f9092:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
