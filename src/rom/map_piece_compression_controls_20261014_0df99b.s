.setcpu "65816"
.segment "CODE"
.org $F99B
map_control_0df99b:
    .byte $F5 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
