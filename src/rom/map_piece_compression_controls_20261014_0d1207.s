.setcpu "65816"
.segment "CODE"
.org $1207
map_control_0d1207:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $CF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
