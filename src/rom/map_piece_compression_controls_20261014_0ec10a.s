.setcpu "65816"
.segment "CODE"
.org $C10A
map_control_0ec10a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
