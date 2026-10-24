.setcpu "65816"
.segment "CODE"
.org $99DA
map_control_0f99da:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
