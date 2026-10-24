.setcpu "65816"
.segment "CODE"
.org $443B
map_control_0d443b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
