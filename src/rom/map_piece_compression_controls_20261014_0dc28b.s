.setcpu "65816"
.segment "CODE"
.org $C28B
map_control_0dc28b:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
