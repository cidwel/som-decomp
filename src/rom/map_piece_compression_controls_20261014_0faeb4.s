.setcpu "65816"
.segment "CODE"
.org $AEB4
map_control_0faeb4:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
