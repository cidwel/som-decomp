.setcpu "65816"
.segment "CODE"
.org $DBAE
map_control_0edbae:
    .byte $E1 ; previous-row copy count
