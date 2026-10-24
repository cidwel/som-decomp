.setcpu "65816"
.segment "CODE"
.org $D24B
map_control_0ed24b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
