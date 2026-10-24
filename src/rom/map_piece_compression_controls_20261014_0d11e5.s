.setcpu "65816"
.segment "CODE"
.org $11E5
map_control_0d11e5:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
