.setcpu "65816"
.segment "CODE"
.org $D86A
map_control_0ed86a:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E1 ; previous-row copy count
