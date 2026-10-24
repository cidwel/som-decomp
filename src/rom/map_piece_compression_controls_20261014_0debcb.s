.setcpu "65816"
.segment "CODE"
.org $EBCB
map_control_0debcb:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
