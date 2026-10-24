.setcpu "65816"
.segment "CODE"
.org $BBFF
map_control_0dbbff:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
