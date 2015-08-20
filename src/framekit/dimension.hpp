#ifndef DIMENSION_H
#define DIMENSION_H


class Dimension
{
    public:
        /** Default constructor */
        Dimension();
        /** Default destructor */
        virtual ~Dimension();
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Dimension& operator=(const Dimension& other);
        /** Access m_XPos
         * \return The current value of m_XPos
         */
        unsigned int GetXPos() { return m_XPos; }
        /** Set m_XPos
         * \param val New value to set
         */
        void SetXPos(unsigned int val) { m_XPos = val; }
        /** Access m_YPos
         * \return The current value of m_YPos
         */
        unsigned int GetYPos() { return m_YPos; }
        /** Set m_YPos
         * \param val New value to set
         */
        void SetYPos(unsigned int val) { m_YPos = val; }
        /** Access m_Width
         * \return The current value of m_Width
         */
        unsigned int GetWidth() { return m_Width; }
        /** Set m_Width
         * \param val New value to set
         */
        void SetWidth(unsigned int val) { m_Width = val; }
        /** Access m_Height
         * \return The current value of m_Height
         */
        unsigned int GetHeight() { return m_Height; }
        /** Set m_Height
         * \param val New value to set
         */
        void SetHeight(unsigned int val) { m_Height = val; }
    protected:
    private:
        unsigned int m_XPos; //!< Member variable "m_XPos"
        unsigned int m_YPos; //!< Member variable "m_YPos"
        unsigned int m_Width; //!< Member variable "m_Width"
        unsigned int m_Height; //!< Member variable "m_Height"
};

#endif // DIMENSION_H
