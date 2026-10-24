.setcpu "65816"
.segment "CODE"
.org $ADBD
map_control_0dadbd:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
