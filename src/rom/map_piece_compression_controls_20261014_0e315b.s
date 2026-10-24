.setcpu "65816"
.segment "CODE"
.org $315B
map_control_0e315b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
