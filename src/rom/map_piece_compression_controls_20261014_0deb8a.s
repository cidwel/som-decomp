.setcpu "65816"
.segment "CODE"
.org $EB8A
map_control_0deb8a:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
