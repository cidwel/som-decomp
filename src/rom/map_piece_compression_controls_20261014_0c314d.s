.setcpu "65816"
.segment "CODE"
.org $314D
map_control_0c314d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
