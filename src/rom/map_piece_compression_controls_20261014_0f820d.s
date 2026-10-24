.setcpu "65816"
.segment "CODE"
.org $820D
map_control_0f820d:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
