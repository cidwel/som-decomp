.setcpu "65816"
.segment "CODE"
.org $87A6
map_control_0f87a6:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
