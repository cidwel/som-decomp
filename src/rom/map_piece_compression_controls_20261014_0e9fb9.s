.setcpu "65816"
.segment "CODE"
.org $9FB9
map_control_0e9fb9:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
