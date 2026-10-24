.setcpu "65816"
.segment "CODE"
.org $243C
map_control_0c243c:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
