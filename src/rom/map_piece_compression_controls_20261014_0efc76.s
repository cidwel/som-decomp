.setcpu "65816"
.segment "CODE"
.org $FC76
map_control_0efc76:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
