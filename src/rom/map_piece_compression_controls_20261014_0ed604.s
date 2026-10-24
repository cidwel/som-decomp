.setcpu "65816"
.segment "CODE"
.org $D604
map_control_0ed604:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
