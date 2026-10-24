.setcpu "65816"
.segment "CODE"
.org $0EB6
map_control_0c0eb6:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
