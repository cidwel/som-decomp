.setcpu "65816"
.segment "CODE"
.org $D140
map_control_0fd140:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
