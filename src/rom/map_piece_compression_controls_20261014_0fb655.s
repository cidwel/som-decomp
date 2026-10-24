.setcpu "65816"
.segment "CODE"
.org $B655
map_control_0fb655:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
