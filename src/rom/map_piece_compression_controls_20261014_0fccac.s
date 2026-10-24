.setcpu "65816"
.segment "CODE"
.org $CCAC
map_control_0fccac:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
