.setcpu "65816"
.segment "CODE"
.org $FCCF
map_control_0ffccf:
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
