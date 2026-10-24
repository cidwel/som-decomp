.setcpu "65816"
.segment "CODE"
.org $BBCE
map_control_0dbbce:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
