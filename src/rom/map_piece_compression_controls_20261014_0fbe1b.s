.setcpu "65816"
.segment "CODE"
.org $BE1B
map_control_0fbe1b:
    .byte $E0 ; previous-row copy escape
    .byte $B2 ; row-distance/count
