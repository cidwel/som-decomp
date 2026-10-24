.setcpu "65816"
.segment "CODE"
.org $F335
map_control_0df335:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
