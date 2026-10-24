.setcpu "65816"
.segment "CODE"
.org $925F
map_control_0d925f:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
