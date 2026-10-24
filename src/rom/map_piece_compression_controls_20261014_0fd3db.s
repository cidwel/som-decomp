.setcpu "65816"
.segment "CODE"
.org $D3DB
map_control_0fd3db:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $78 ; row-distance/count
