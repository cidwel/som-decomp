.setcpu "65816"
.segment "CODE"
.org $656B
map_control_0c656b:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
