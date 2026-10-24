.setcpu "65816"
.segment "CODE"
.org $AD35
map_control_0dad35:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
