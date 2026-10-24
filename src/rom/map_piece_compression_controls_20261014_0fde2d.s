.setcpu "65816"
.segment "CODE"
.org $DE2D
map_control_0fde2d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
