.setcpu "65816"
.segment "CODE"
.org $820D
map_control_0d820d:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
