.setcpu "65816"
.segment "CODE"
.org $C536
map_control_0dc536:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
