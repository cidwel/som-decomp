.setcpu "65816"
.segment "CODE"
.org $054B
map_control_0f054b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
