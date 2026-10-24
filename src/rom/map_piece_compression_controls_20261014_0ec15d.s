.setcpu "65816"
.segment "CODE"
.org $C15D
map_control_0ec15d:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
