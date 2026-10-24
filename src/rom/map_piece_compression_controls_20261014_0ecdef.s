.setcpu "65816"
.segment "CODE"
.org $CDEF
map_control_0ecdef:
    .byte $E2 ; previous-row copy count
